import java.util.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
public class QuoteOfTheDay
{
	public String quote;
	public String date;
	public String s_day;
	public int SIZE=5;
	public class Quote implements Runnable
	{

		String []qmorning=new String[SIZE];
		String []qevening=new String[SIZE];
		String []qnight=new String[SIZE];
		String []qspecial=new String[SIZE];
		Quote()
		{
			qmorning[0]="When you arise in the morning, think of what a precious privilege it is to be alive - to breathe, to think, to enjoy, to love. -Marcus Aurelius";
			qmorning[1]="When you rise in the morning, give thanks for the light, for your life, for your strength. Give thanks for your food and for the joy of living. If you see no reason to give thanks, the fault lies in yourself. -Tecumseh";
			qmorning[2]="No matter how bad things are, you can at least be happy that you woke up this morning. -D. L. Hughley";
			qmorning[3]="Morning without you is a dwindled dawn. -Emily Dickinson";
			qmorning[4]="Morning is an important time of day, because how you spend your morning can often tell you what kind of day you are going to have. - Lemony Snicket, The Blank Book";
			qevening[0]="The evening star is the most beautiful of all stars. -Sappho, Sappho: A New Translation";
			qevening[1]="As we walk back, it feels like the city is engulfing us.In the evening, it's like it dies, waiting to be born again the next morning. -Markus Zusak, Fighting Ruben Wolfe";
			qevening[2]="I see an evening sky strewn with diamonds and glass. -E.J. Hill, Ashes of Glass";
			qevening[3]="The last thought in the evening is often the first one in the morning. -Giovannie de Sadeleer";
			qevening[4]="The evening, lacking intelligent relations, crumbles down into the haze of the horizon. -Federico García Lorca, The Dialogue of Two Snails";
			qnight[0]="The darker the night, the brighter the stars.The deeper the grief, the closer is God! - Fyodor Dostoevsky, Crime and Punishment";
			qnight[1]="Each night, when I go to sleep, I die. And the next morning, when I wake up, I am reborn. -Mahatma Gandhi";
			qnight[2]="The longest way must have its close - the gloomiest night will wear on to a morning. -Harriet Beecher Stowe, Uncle Tom's Cabin";
			qnight[3]="Some nights are made for torture, or reflection, or the savoring of loneliness. - Poppy Z.Brite";
			qnight[4]="Those who dream by day are cognizant of many things which escape those who dream only by night. -Edgar Allan Poe, Eleonora";
			qspecial[0]="Freedom is the atmosphere in which humanity thrives. Breathe it in. - Richelle E. Goodrich, Making Wishes";
			qspecial[1]="Those who educate children well are more to be honored than they who produce them; for these only gave them life, those the art of living well. -Aristotle";
			qspecial[2]="Every child comes with the message that God is not yet discouraged of man. -Rabindranath Tagore";
		}
		public void run()
		{
			s_day="";
			Date d=new Date();
			int h=d.getHours();
			int m=d.getMonth();
			int s=d.getSeconds();
			int sp=s%5;
			m++;
			int day=d.getDate();
			date="Date: "+Integer.toString(day)+"/"+Integer.toString(m)+"/"+Integer.toString(d.getYear()-100)+" : ";;
			//System.out.println(h+" "+m+" "+day);
			Random r=new Random();
			int ran=r.nextInt(SIZE);//for larger database
			if(m==8 && day==15)
			{
				s_day="Independence Day.";
				quote=qspecial[0];
			}
			else if(m==9 && day==5)
			{
				s_day="Teacher's Day.";
				quote=qspecial[1];
			}
			else if(m==11 && day==14)
			{
				s_day="Children's Day.";
				quote=qspecial[2];
			}
			else 
			{
				if(h<12)
					quote=qmorning[sp];
				else if (h<20)
					quote=qevening[sp];
				else
					quote=qnight[sp];
			}
		}	
	}
	public class Display
	{
		JFrame frame;
		JPanel p1,p2;
		JLabel d;
		JLabel q;
		public Display()
		{
			frame=new JFrame("Quote Of The Day");
			p1=new JPanel();
			p1.setLayout(new BorderLayout());
			//p2=new JPanel();
			frame.setSize(1000,100);
			//frame.getContentPane().setBackground(Color.red);
			//frame.setBackground(Color.RED);
			//Container c = frame.getContentPane();
			p1.setBackground(Color.ORANGE);
			//frame.setContentPane(p1);
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			//p.setLayout(new FlowLayout());
			buildpanel();
			//setContentPane();
			frame.add(p1);
			//add(p2);
			frame.setVisible(true);
		}
		private void buildpanel()
		{

			d=new JLabel(date);
			q=new JLabel(quote);
			d.setFont(new Font("Bebas Neue", Font.PLAIN, 14));
			q.setFont(new Font("Serif", Font.PLAIN, 12));
			p1.add(d,BorderLayout.NORTH);
			//p1.setLayout(new flowlayout());
			p1.add(q,BorderLayout.WEST);
			if(s_day.equals("")==false)
			{
				JLabel n=new JLabel(s_day);
				q.setFont(new Font("Comic Sans MS", Font.ITALIC, 12));
				p1.add(n,BorderLayout.SOUTH);
			}
		}
	}
	public static void main(String args[]) throws InterruptedException
	{
		QuoteOfTheDay qd=new QuoteOfTheDay();
		Quote q=qd.new Quote();
		Thread t=new Thread(q);
		t.start();
		if(t.isAlive())
			t.join();
		Display d=qd.new Display();
	}
}