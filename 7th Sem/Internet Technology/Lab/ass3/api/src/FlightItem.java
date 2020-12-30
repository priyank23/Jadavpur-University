import java.io.*;
import java.util.*;

public class FlightItem {
    public String origin;
    public String destination;
    public Date departure;
    public int cost;
    public int isOffer;
    public int offercost;
    public Date validity;
    public String company;

    FlightItem(String or, String dest, Date depart, int cst, int offerCst, int offer, Date validTill, String com ) {
        origin=or;
        destination=dest;
        departure=depart;
        cost=cst;
        isOffer=offer;
        offercost=offerCst;
        validity=validTill;
        company=com;
    };
}
