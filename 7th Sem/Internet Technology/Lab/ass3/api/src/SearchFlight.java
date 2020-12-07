
import javax.servlet.*;
import java.io.*;
import java.util.*;
import javax.servlet.http.*;

public class SearchFlight extends HttpServlet
{
    @Override 
    public void doPost(HttpServletRequest request,
                        HttpServletResponse response)
                throws IOException, ServletException
    {
        
        String o=request.getParameter("ORIGIN");
        String d=request.getParameter("DESTINATION");
        
	response.setContentType("text/plain");
        response.setCharacterEncoding("UTF-8");

        PrintWriter out = response.getWriter();
        
        
        Date loadtime=new java.util.Date();
        
        FlightList flt = new FlightList();

        Flight[] fll=flt.fl;
        int tc=flt.count;

        for(int i=0; i<tc;i++)
        {
            Flight c=fll[i];
            if(o.equals(c.origin)&& d.equals(c.destination))
            {
                if(c.startdate.after(loadtime))
                {
                    out.println(c.origin+"\t"+c.destination+"\t"+c.company+"\t"+String.valueOf(c.startdate)+"\t"+String.valueOf(c.cost));
                }
            }
        }
                  
    }

}
