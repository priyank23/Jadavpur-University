package ass2;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.time.*;

public class student
{
    protected StringBuilder roll;
    protected String name;
    protected Date date;
    int dept;
    student()
    {
        roll=new StringBuilder();
        roll.append("XXXX18000");
    }
    public String getRoll()
    {
        return roll.toString();
    }
    void setName(String nm)
    {
        name=nm;
    }
    static LocalDate get_adm_Date()
    {
        return LocalDate.now();
    }
    void gen_roll(int dep_code,int std_no)
    {
        if(dep_code==1) roll.replace(0,9,"BCSE18000");
        else if(dep_code==2) roll.replace(0,9,"BCHE18000");
        else if(dep_code==3) roll.replace(0,9,"ELEC18000");
        else if(dep_code==4) roll.replace(0,9,"MECH18000");
        else{
            System.out.println("Error code!!");
            return;
        }
        roll.setCharAt(6,(char)((std_no/100)+48));
        roll.setCharAt(7,(char)(((std_no/10)%10)+48));
        roll.setCharAt(8,(char)((std_no%10)+48));
       // System.out.println("Roll:"+roll);
        date= java.sql.Date.valueOf(get_adm_Date());
      //  System.out.println("Date of registration: " + date);
    }
}
