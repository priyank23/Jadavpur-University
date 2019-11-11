import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.time.*;
import javax.swing.border.Border;
import javax.swing.BorderFactory;
public class linked_list extends JFrame
{
    JButton List1,List2;
    JPanel choice;
    JLabel framelabel;

    linked_list()
    {
        super("START");
        setSize(800,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new GridLayout(4,5));

        framelabel=new JLabel("Choose type:");
        framelabel.setHorizontalAlignment(JLabel.CENTER);
        framelabel.setVerticalAlignment(JLabel.CENTER);
        GridLayout grid=new GridLayout(1,2,10,10);
        choice=new JPanel(grid);
        choice.setSize(40,40);
        List1=new JButton("Strings");
        List2=new JButton("Students");
        choice.add(List1);
        choice.add(List2);
        add(framelabel);
        add(choice);
        setVisible(true);
	

        List1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){					
					StringLinkedList sll=new StringLinkedList();
					sll.setVisible(true);
			}
		});
		List2.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae){

					StudentLinkedList sll=new StudentLinkedList();
					sll.setVisible(true);
			}
		});
    }
    public static void main(String args[])
    {

        linked_list llist=new linked_list();
    }
}
class ObjectNode
{
    Object details;
    ObjectNode next;
}
class BasicLinkedList extends JFrame
{
    ObjectNode head, tail;
    JPanel buttons, list;
    JLabel framelabel,buttonchoice;
    JButton insFront,insBack,delFront,searchKey;
	Container c1;

    public BasicLinkedList(String framename)
    {
        super(framename);
        c1=getContentPane();
        this.setSize(650,600);
        this.setLayout(new BorderLayout(10,10));
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.buildPanel();
        head=null;
        tail=null;
        c1.add(buttons,BorderLayout.NORTH);
        c1.add(list,BorderLayout.CENTER);
		

    };
    public void buildPanel()
    {
		GridLayout gl=new GridLayout(3,4,0,0);
        gl.setVgap(5);
		buttons=new JPanel(gl);
	    list=new JPanel(new FlowLayout(FlowLayout.LEFT));
		buttonchoice=new JLabel("Choose method:");
		insFront=new JButton("Insert front");
		insBack=new JButton("Insert rear");
		delFront=new JButton("Delete front");
		searchKey=new JButton("Search a node");
		buttons.add(buttonchoice);
		buttons.add(insFront);
		buttons.add(insBack);
		buttons.add(delFront);
		buttons.add(searchKey);
	};
    public void insert_at_front(Object obj)
    {
        
        ObjectNode temp=new ObjectNode();
		temp.details=obj;
		temp.next=head;
		if(head==null)
        {
        
			head=new ObjectNode();
			head.details=obj;
			head.next=null;	
			tail=head;
            return;
		}
		head=temp;
    };
    public void insert_at_back(Object obj)
    {

        ObjectNode temp=new ObjectNode();
		temp.details=obj;
		temp.next=null;
		if(tail==null)
        {
			tail=new ObjectNode();
			tail.details=obj;
			tail.next=null;	
			head=tail;
            return;
		}
        tail.next=temp;
		tail=temp;
    };
    public Object delete_at_front()
    {
	
        Object n;
        if(head==null)
        {
            return null;
		}
		if(head.next==null)
		{	
            n=head.details;
			head=null;
			tail=null;
            return n;
		}
        n=head.details;
		head=head.next;
		System.gc();
        return n;
    };
}
class StudentForm extends JFrame
{
    JLabel name,roll,dept,dateBox,rollBox;
    JTextField takeName,takeRoll;
    Date dt;
    JRadioButton cse,ele,che;
    JPanel deptChoose;
    JButton submit;
    Student s1;
    StudentForm()
    {
        super("Enter student details");
        setSize(400,300);
        setLayout(new GridLayout(6,2));
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        designForm();


    }
    void designForm()
    {
        name=new JLabel("Name :   ",SwingConstants.RIGHT);
        dept=new JLabel("Dept :   ",SwingConstants.RIGHT);
        dt=new Date();
        takeName=new JTextField();
        dateBox=new JLabel("Date:"+LocalDate.now().toString());
        deptChoose=new JPanel(new FlowLayout(FlowLayout.LEFT));
        cse=new JRadioButton("CSE");
        che=new JRadioButton("CHE");
        ele=new JRadioButton("ELE");
        submit=new JButton("Add Student");
        ButtonGroup bg=new ButtonGroup();
        bg.add(cse);
		bg.add(che);
		bg.add(ele);
        deptChoose.add(cse);
        deptChoose.add(ele);
        deptChoose.add(che);
        add(name);
        add(takeName);
        add(dept);
        add(deptChoose);
        add(dateBox);
        add(submit);
       
    }
    public int setStudent()
    {
        s1=new Student();
        String nm=takeName.getText();
        int dept_id=-1;
        if(nm.trim().equals(""))
		{
			s1=null;
			return 0;
		}
        else
        {
            s1.setName(nm);
        }
        if(cse.isSelected())
        {
            s1.setDept(0);
            dept_id=0;
        }
        else if(che.isSelected())
        {
            s1.setDept(1);
            dept_id=1;
        }
        else if(ele.isSelected())
        {
            s1.setDept(2);
            dept_id=2;
        }
        else 
            return 1;
        s1.setAdmDate();
        s1.generate_roll(dept_id);
        return 2;
    }
}
class Student 
{
    public String name;
    public String department;
    public String roll;
    public int did;
    public Date admission;
    void setName(String n1)
    {
        this.name=n1;
    }
    void setDept(int d1)
    {
        department=Department.department[d1];
        did=d1;
    }
    void setAdmDate()
    {
        admission=new Date();
    }
    public void generate_roll(int d1)
    {
        int temp=++Department.count[did];
        roll=department;
        if(temp<10)
            roll=roll+"000"+temp;
        else if (temp<100)
            roll=roll+"00"+temp;
    }
    public String getRoll()
    {
        return roll;
    }

}
class Department
{
    static int count[]=new int[3];
	static String department[]={"BCSE","BCHE","BELE"}; 
}
class StudentLinkedList extends BasicLinkedList
{
    JLabel  word ;
    JTextField input;

	
    StudentLinkedList()
    {   
        super("Student");
		
        word=new JLabel("Enter roll here:",SwingConstants.RIGHT);
        input=new JTextField();

		Border frameBorder1=BorderFactory.createLineBorder(Color.BLACK,2);
		input.setBorder(frameBorder1);
        buttons.add(word);
        buttons.add(input);



        insFront.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
            {
                StudentForm sf1=new StudentForm();
                sf1.setVisible(true);
                sf1.submit.addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent ae)
                    {

						int result=sf1.setStudent();
						if(result==0)
							{JOptionPane.showMessageDialog(null,"Name not found");return;}
						else if(result==1)
							{JOptionPane.showMessageDialog(null,"Department not choosen");return;}
						insert_at_front(sf1.s1);
                        display(-1);
						sf1.dispose();
					}
				});
                
            }
		});
        insBack.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
            {
                StudentForm sf1=new StudentForm();
                sf1.setVisible(true);
                sf1.submit.addActionListener(new ActionListener(){
					public void actionPerformed(ActionEvent ae)
                    {

						int result=sf1.setStudent();
						if(result==0)
							{JOptionPane.showMessageDialog(null,"Enter a name!!!");return;}
						else if(result==1)
							{JOptionPane.showMessageDialog(null,"Select a department!!!");return;}
						insert_at_back(sf1.s1);
                        display(-1);
						sf1.dispose();
					}
				});
			}
		});
        delFront.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
            {

                delete_at_front();
				display(-1);
			}
		});
        searchKey.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
            {

				String w=input.getText();
				if(w.trim().length()!=8)
                {
                    JOptionPane.showMessageDialog(null,"Invalid");
                    return;
                }
                if(validRoll(w.trim())==-1)
                {
                    JOptionPane.showMessageDialog(null,"Invalid");
                    return;
                }	
                int color=search(w.trim());
                display(color);
			}
		});
    };
    public int validRoll(String roll)
    {
		String dept=roll.substring(0,4);
        int dept_id=-1,rollInt;
		for(int i=0;i<3;i++)
		{
			if(dept.equalsIgnoreCase(Department.department[i]))
			{
				dept_id=i;
				break;
			}
		}
		if(dept_id==-1)
		{
			return -1;
		}
		String indx=roll.substring(6);
		rollInt=Integer.parseInt(indx);
		if(rollInt>Department.count[dept_id])
		{
			return -1;
		}
		return 1;
		
	}
    public int search(String key)
    {
		ObjectNode temp=head;
		int count=0;
		while(temp!=null){
			count++;
			Student ref=(Student)temp.details;
			String value=ref.getRoll();
			if(value.equalsIgnoreCase(key))
				return count;
			temp=temp.next;
		}
		return -1;
	}
    public void display(int color)
    {
		ObjectNode temp=head;
		list.removeAll();
		repaint();
		Student stu_Temp;
		JLabel headPointer=new JLabel("START>");
		list.add(headPointer);
		validate();
        int count=0;		
		while(temp!=null)
        {
            count++;
			stu_Temp=(Student)temp.details;

			if(color==count)
				nodeRear(stu_Temp,1);
			else
				nodeRear(stu_Temp,0);

			temp=temp.next;
		}
		JLabel nullNode=new JLabel("END");
		list.add(nullNode);
		validate();
	}
    public void nodeRear(Student stud,int color)
    {
		JPanel nodeArrow=new JPanel(new FlowLayout());
		JLabel node=new JLabel(stud.getRoll(),SwingConstants.CENTER);
		Color bordCol;
        int extra,thickness;
		if(color==0)
		{
			extra=0;
			bordCol=Color.BLACK;
			thickness=2;
		}
		else
		{
			extra=4;
			bordCol=Color.RED;
			thickness=4;		
		}	
		node.setPreferredSize(new Dimension(85+extra,50+extra));
		Border nodeBorder=BorderFactory.createLineBorder(bordCol,thickness);
	  	node.setBorder(nodeBorder);
		nodeArrow.add(node);
		arrow arr=new arrow(node.getX(),node.getY(),node.getX()+10,node.getY());
		nodeArrow.add(arr,BorderLayout.CENTER);
		nodeArrow.setBackground(Color.CYAN);
		list.add(nodeArrow);
		validate();
	}
}
class StringLinkedList extends BasicLinkedList
{
    JLabel  word ;
    JTextField input;

    StringLinkedList()
    {
        super("String");
		
        word=new JLabel("Enter string:",SwingConstants.RIGHT);
        input=new JTextField();
   
		Border frameBorder=BorderFactory.createLineBorder(Color.BLACK,2);
	  	input.setBorder(frameBorder);
        buttons.add(word);
        buttons.add(input);

        insFront.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
            {
                String w=input.getText();
				if(w.trim().equalsIgnoreCase("")){
					JOptionPane.showMessageDialog(null,"Enter a string");
					return;
				}

				input.setText("");
				insert_at_front(w);
				display(-1);
			

			}
		});
        insBack.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
            {
                String w=input.getText();				
				if(w.trim().equalsIgnoreCase("")){
					JOptionPane.showMessageDialog(null,"Enter a string");
					return;
				}
				
				input.setText("");
				insert_at_back(w);
				display(-1);
				

			}
		});
        delFront.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
            {
                String res=(String)delete_at_front();
				display(-1);
				

			}
		});
        searchKey.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent ae)
            {

                String w=input.getText();				
				int res=search(w);
				if(w.trim().equalsIgnoreCase("")){
					JOptionPane.showMessageDialog(null,"Enter a string first");
					return;
				}
				if(res==-1){
					display(-1);
					
				}
				else
				{
					display(res);
					
				}

			}
		});
    };
    public int search(String key)
    {
		ObjectNode temp=head;
		int count=0;
		while(temp!=null){
			count++;
			String value=(String)temp.details;
			if(value.equalsIgnoreCase(key))
				return count;
			temp=temp.next;
		}
		return -1;
	}
    public void display(int color)
    {
		ObjectNode temp=head;
		list.removeAll();
		repaint();
		JLabel headPointer=new JLabel("START>");
		list.add(headPointer);
		validate();
        int count=0;		
		while(temp!=null)
        {
            count++;
			if(color==count)
				nodeRear((String)temp.details,1);
			else
				nodeRear((String)temp.details,0);

			temp=temp.next;
		}
		JLabel nullNode=new JLabel("END");
		list.add(nullNode);
		validate();
	}
    public void nodeRear(String word,int color)
    {
		JPanel nodeArrow=new JPanel(new FlowLayout());
		JLabel node=new JLabel(word,SwingConstants.CENTER);
		Color bordCol;
        int extra,thickness;
		if(color==0)
		{
			extra=2;
			bordCol=Color.BLACK;
			thickness=2;
		}
		else
		{
			extra=6;
			bordCol=Color.RED;
			thickness=4;		
		}	
		node.setPreferredSize(new Dimension(80+extra,50+extra));
		Border nodeBorder=BorderFactory.createLineBorder(bordCol,thickness);
	  	node.setBorder(nodeBorder);
		nodeArrow.add(node);
		arrow arr=new arrow(node.getX(),node.getY(),node.getX()+10,node.getY());
		nodeArrow.add(arr,BorderLayout.EAST);
		list.add(nodeArrow);
		validate();
	}
}
class arrow extends JPanel
{
	int x1,y1,x2,y2;
	arrow(int x1,int y1,int x2,int y2){
		this.x1=x1;
		this.y1=y1;
		this.x2=x2;
		this.y2=y2;
	}
	protected void paintComponent(Graphics g){
		int x[]={x1+2,x1+2,x1-8,x1-8,x1+2,x1+2,x2+2};
		int y[]={y1,y1+4,y1+4,y1+6,y1+6,y1+10,y1+5};
		g.fillPolygon(x,y,7);
	}
}
