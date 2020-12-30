import javax.servlet.*;
import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat;
import javax.servlet.http.*;

public class Deals extends HttpServlet
{
    @Override 
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setHeader("Access-Contol-Allow-Origin", "http://localhost:3000/");
        response.setHeader("Access-Control-Allow-Methods", "GET");
	    response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        PrintWriter out = response.getWriter();
        
        Date reqTime=new java.util.Date();
        
        FlightList flightList = new FlightList();
        SimpleDateFormat fmt =new SimpleDateFormat ("E yyyy.MM.dd 'at' hh:mm:ss a zzz");
        FlightItem[] flights=flightList.flights;
        int flightCount=flightList.count;
	    String toSend = "[";
        for(int i=0; i<flightCount;i++)
        {
            FlightItem c=flights[i];
            if(c.isOffer==1 && reqTime.before(c.validity))
            {
                toSend += "{\"origin\":\""+c.origin+"\",\"destination\":\""+c.destination+"\",\"company\":\""+c.company+"\",\"departure\":\""+fmt.format(c.departure)+"\",\"cost\":\""+String.valueOf(c.cost)+"\",\"offerCost\":\""+String.valueOf(c.offercost)+"\",\"validity\":\""+fmt.format(c.validity)+"\"},";
            }
        }
        toSend = toSend.substring(0, toSend.length()-1) + "]";
        out.print(toSend);
    }

}



