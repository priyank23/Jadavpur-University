import javax.servlet.*;
import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat;
import java.util.stream.Collectors;
import javax.servlet.http.*;
import org.json.simple.*;
import org.json.simple.parser.*;

public class FlightSearchApi extends HttpServlet
{
    @Override 
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

		String query=request.getReader().lines().collect(Collectors.joining());
		
		JSONParser parser = new JSONParser();
		JSONObject obj = new JSONObject();

		try {
			obj = (JSONObject)parser.parse(query);
		} catch(ParseException e) {}

		String origin = (String)obj.get("origin");
		String dest = (String)obj.get("destination");
		String depart = (String)obj.get("depart");
		Date departDate = parseDate(depart);

		response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        PrintWriter out = response.getWriter();
        JSONArray flights= new JSONArray();
        Date loadtime=new Date();
        
        FlightList flightList = new FlightList();

		SimpleDateFormat fmt =new SimpleDateFormat ("E yyyy.MM.dd 'at' hh:mm:ss a zzz");
        for(int i=0; i<flightList.count;i++) {
            FlightItem flight=flightList.flights[i];
            if(origin.equals(flight.origin)&& dest.equals(flight.destination)) {
                if(flight.departure.after(departDate)) {
					JSONObject fl = new JSONObject();
					fl.put("origin", flight.origin);
					fl.put("destination", flight.destination);
					fl.put("company", flight.company);
					fl.put("departure", fmt.format(flight.departure));
					if(flight.isOffer == 0) fl.put("cost", flight.cost);
					else fl.put("cost", flight.offercost);
					flights.add(fl);
				}
            }
        }
        out.print(flights.toString());
    }

    public static Date parseDate(String date) {
     	try {
         	return new SimpleDateFormat("yyyy-MM-dd").parse(date);
     	} catch (Exception e) {
        	return null;
     	}
    }
}
