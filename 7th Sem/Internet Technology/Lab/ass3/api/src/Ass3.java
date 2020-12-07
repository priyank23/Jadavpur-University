

import javax.servlet.*;
import java.io.*;
import java.util.*;
import javax.servlet.http.*;


public class Ass3 extends HttpServlet
{
    @Override 
    public void doGet(HttpServletRequest request,
                        HttpServletResponse response)
                throws IOException, ServletException
    {
        response.setHeader("Access-Contol-Allow-Origin", "http://localhost:3000/");
        response.setHeader("Access-Control-Allow-Methods", "GET");
	response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        PrintWriter out = response.getWriter();

        
        Date loadtime=new java.util.Date();
        
        FlightList flt = new FlightList();

        Flight[] fll=flt.fl;
        int tc=flt.count;
	String toSend = "[";
        for(int i=0; i<tc;i++)
        {
            Flight c=fll[i];
            if(c.isOffer==1)
            {
                if(loadtime.before(c.validity))
                toSend += "{\"origin\":\""+c.origin+"\",\"destination\":\""+c.destination+"\",\"company\":\""+c.company+"\",\"departure\":\""+String.valueOf(c.startdate)+"\",\"cost\":\""+String.valueOf(c.cost)+"\",\"offerCost\":\""+String.valueOf(c.offercost)+"\",\"validity\":\""+String.valueOf(c.validity)+"\"},";
            }
        }
	toSend = toSend.substring(0, toSend.length()-1) + "]";
	out.print(toSend);

    }

}



