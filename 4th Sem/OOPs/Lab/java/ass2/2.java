import java.io.*;

/*Runnable class to mask the password with asterisk*/
class EraserThread implements Runnable {          
   private boolean stop;
   public EraserThread(String prompt)
   {
       System.out.print("Enter the password: ");
   }
   public void run () {
    stop = true;
    while (stop) {
            System.out.print("\010*");
    try {
            Thread.currentThread().sleep(1);
        } 
    catch(InterruptedException ie){
            ie.printStackTrace();
        }
      }
   }
}

/*class to store basic details of an item*/
class item
{
    StringBuilder code = new StringBuilder();
    String name = new String();
    double price;
    int quan;
    item()
    {
        code.append("XXX000");
    }
    String get_name()     //function to set the name of an item
    {
    	return name;
    }
    StringBuilder get_code() //function to return item code
    {
    	return code;
    }
    double ret_price()       //function to return price of an item
    {
    	return price;
    }
    int ret_qty()            //function to return quantity of the item
    {
    	return quan;
    }
    void set_qty(int qty)     //function to set quantity of the item
    {
        quan=qty;
    }
    /*function for taking input in an item*/
    void get_item(int i) throws IOException  
    {
        BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
        System.out.print("NAME:");
        name=bf.readLine();
        System.out.print("QUANTITY:");
        quan=Integer.parseInt(bf.readLine());
        System.out.print("PRICE:");
        double pr;
        pr= Double.parseDouble(bf.readLine());
        set_price(pr);
        gen_code(name,i);   //generating cod for the item
    }
    void disp_item()         //function to display the item details
    {
        System.out.println("CODE: " + code );
        System.out.println("NAME: " + name);
        System.out.println("PRICE :" + price);
        System.out.println("STOCK :" + quan);
    }
    void set_price(double pr)    //function to set the price of an item
    {
        price=pr;
    }
    void gen_code(String nm, int qty )   //function for generating item code
    {
        code.setCharAt(0, Character.toUpperCase(nm.charAt(0)));
        if(nm.length()>=2)
        code.setCharAt(1, Character.toUpperCase(nm.charAt(1)));
        if(nm.length()>=3)
        code.setCharAt(2, Character.toUpperCase(nm.charAt(2)));
        code.setCharAt(3,(char)((qty/100)+48));
        code.setCharAt(4,(char)(((qty/10)%10)+48));
        code.setCharAt(5,(char)((qty%10)+48));
    }
}
/*class itemlist to store all the items and to perform all the appropriate functions*/
class itemlist
{
    item[] l1 = new item[100];
    int n_items;
    itemlist(int n)
    {
        n_items=n;
    }
    itemlist()
    {
        n_items=0;
    }
	int get_num(int n)
	{
		n_items=n;
        return n_items;
	}
    int find_code(String temp,int n)   //function to return index of an item in the list
    {
        for(int i=0;i<n-1;i++)
        {
            if(temp.equals(l1[i].get_code().toString()))
                return i;
        }
        return -1;
    }
    /*function to prepare a list */
    void prepare_list() throws IOException
    {
        int j=0;
        for(int i=0;i<n_items;i++)
        {
            item temp = new item();
            System.out.println("\nITEM " + (i+1));
            temp.get_item(i+1);
            int k=find_code(temp.get_code().toString(),i+1);
            if(k==-1) {
                l1[j]=temp;
                j++;
                System.out.println();
                temp.disp_item();
            }
            else l1[k].set_qty(temp.ret_qty());
        }
    }
    /*function to update the list after an operation */
    void update_list() throws IOException
    {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int ch,k,sl;
        String s;
        System.out.println("1.Add an Item.\n2.Update existing stock.");
        ch= Integer.parseInt(bf.readLine());
        item temp =new item();
        switch(ch)
        {
        case 1:
            //n_items++;
            temp.get_item(n_items+1);
            k=find_code(temp.get_code().toString() , n_items+1);
            if(k==-1) l1[n_items++]=temp; 
            else System.out.println("Item already exists.");
            break;
        case 2:
            System.out.println("Enter the item_code to be updated:");
            s=bf.readLine();
            sl=find_code(s,n_items+1);
            if(sl==-1)
            {
                System.out.println("Item does not exist");
                return;
            }
            System.out.println("Item Code:" + l1[sl].get_code());
            System.out.println("Item Name:" + l1[sl].get_name());
            System.out.println("Quantity:"+l1[sl].ret_qty());
            System.out.println("Price:"+l1[sl].ret_price());
            System.out.print("\nEnter new stock's quantity.");
            int qn;
            double pr;
            qn = Integer.parseInt(bf.readLine());
            l1[sl].set_qty(qn);
            System.out.print("Enter new price:");
            pr=Double.parseDouble(bf.readLine());
            l1[sl].set_price(pr);
            break;
        default: System.out.println("Wrong choice!!!");
                break;
        }
    }
    void disp_list(double price)  //function to display the item list
    {
        System.out.println("Sl.No.\tItem Code\tName\t\tQuan.\tPrice\n");
        for(int i=0;i<n_items;i++)
        {
            if(l1[i].ret_price() >= price)
            System.out.println((i+1) + "\t" + l1[i].get_code() +'\t' +'\t'+l1[i].get_name()+'\t'+'\t'+l1[i].ret_qty()+'\t'+l1[i].ret_price());
        }
    }
};
/*class to store the details of a particular order */
class orderline
{
    String code="XXXXXX";
    int quan;
    int slno;
    orderline()
    {
        quan=0;
        slno=-1;
    }
	int ret_qty()
	{
		return quan;
	}
	String get_code()
	{
		return code;
	}
    /*function to return index of an item in the order */
    int get_item(itemlist l1) throws IOException
    {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String nm;
        System.out.print("NAME:");
        nm=bf.readLine();
        System.out.println(nm);
        ret_code(nm,l1);
        if(code=="XXXXXX"){ 
            System.out.println("Item with that name does not exist!!");
            return -1;
        }
        else
        {
            int q;
            q=get_qty(l1);
            if(q==-1){ 
                System.out.println("Not in Stock!!");
                return -1;
            }
            else quan=q;
            return 0;
        }
    }
    /*function to set itemcode of a particular item from the item list */
    void ret_code(String nm,itemlist l1)
    {
        for(int i=0;i<l1.n_items;i++)
        {
            if(nm.equals(l1.l1[i].get_name())) 
            {
                slno=i;
                code= l1.l1[i].get_code().toString();
            }
        }
        return;
    }
    /*function to get the quantity of an order */
    int get_qty(itemlist l1) throws IOException
    {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int qn;
        if(code=="XXXXXX") return 0;
        System.out.print("Enter quantity:");
        qn=Integer.parseInt(bf.readLine());
        if(l1.l1[slno].ret_qty() >= qn) return qn;
        else return -1;
    }
};
/*class to store the details of a complete order */
class order
{
    int n_items;
    orderline[] list=new orderline[10];
    BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));

    order()
    {
        for(int i=0;i<10;i++)
        {
            list[i]=new orderline();
        }
        n_items=0;
    }
    /*fuction to collect order from the customer */
    void collect_order(itemlist l1) throws IOException
    {
        BufferedReader bf =new BufferedReader(new InputStreamReader(System.in));
		l1.disp_list(0);
		int chk;
        System.out.println("Enter the number of items you want to buy.");
        n_items= Integer.parseInt(bf.readLine());
        for(int i=0;i<n_items;i++)
        {
            System.out.println("ITEM " + (i+1));
        	chk=list[i].get_item(l1);
            System.out.println();
			if(chk==-1)
			{
				i--;
				System.out.println("Enter again.");
			}
        }
    }
    /*function to create the bill on the basis of the order */
    void create_bill(itemlist l1) throws IOException
    {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Sl.No.\tItem Code\tName\tQuan.\tPrice\tAmount\n");
        double[] amount = new double[n_items];
        double sum=0;
        for(int i=0;i<n_items;i++)
        {
            int n=l1.find_code(list[i].get_code(),l1.n_items+1);
            amount[i]=l1.l1[n].ret_price()*list[i].ret_qty();
            sum+=amount[i];
            System.out.println((i+1) +"\t"+list[i].get_code()+'\t'+'\t'+l1.l1[n].get_name()+'\t'+list[i].ret_qty()+'\t'+l1.l1[n].ret_price()+'\t'+amount[i]);
        }
        System.out.println("\n----------------------------------------------------------------\n\t\t\t\t\tTotal: "+sum);
        System.out.println("----------------------------------------------------------------\n");
        System.out.println("\nYou want to purchase?[y/n]");
        char c;
        c=(char)bf.read();
        if(c=='y') update_list(l1);
    }
    /*function to display the final bill once the user agrees to purchase */
    void display_bill(itemlist l1)
    {
        System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println("\t\t\tELECTRONICS WORLD\n");
        System.out.println("----------------------------------------------------------------\n");
        System.out.println("Sl.No.\tItem Code\tName\t\tQuan.\tPrice\tAmount\n");
        double[] amount=new double[n_items];
        double sum=0;
        for(int i=0;i<n_items;i++)
        {
            int n=l1.find_code(list[i].get_code(),l1.n_items+1);
            amount[i]=l1.l1[n].ret_price()*list[i].ret_qty();
            sum+=amount[i];
            System.out.println((i+1)+"\t"+list[i].get_code()+'\t'+'\t'+l1.l1[n].get_name()+'\t'+'\t'+list[i].ret_qty()+'\t'+l1.l1[n].ret_price()+'\t'+amount[i]);
        }
        System.out.println("\n----------------------------------------------------------------\n\t\t\t\t\tTotal: "+sum);
        System.out.println("----------------------------------------------------------------\n");
    }
    /**function to update the item list after a transaction */
    void update_list(itemlist l1)
    {
        for(int i=0;i<n_items;i++)
        {
            int n=l1.find_code(list[i].get_code(),l1.n_items+1);
            l1.l1[n].set_qty(l1.l1[n].ret_qty()-list[i].ret_qty());
        }
    }
}
/*class to manage the transactions of the shop */
class Sales_interface
{
	static String pass="1234";
	static itemlist list1= new itemlist();

/*function to maintain the activities of stock entry operator(SEO) */
static void Admin() throws IOException
{
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	int choice;
	int ch;
	int x;
	while(true)
	{
    System.out.print("\033[H\033[2J");
    System.out.flush();
    System.out.println("\t\t\tELECTRONICS WORLD\n");
	System.out.println("\n 1. Prepare the list.\n 2. Update the list.\n 3. See the list.\n 4. Prepare an order.\n 5. See the price of an item.\n 6. See the items that costs more than a specified amount.\n 7. Exit");
	choice = Integer.parseInt(bf.readLine());
	switch(choice)
	{
		case 1:
        {
			System.out.print("Caution!!Doing this will remove the previously stored list.\nDo you want to continue?[1/0]");
			ch=Integer.parseInt(bf.readLine());
			if(ch!=1) break;
			System.out.println("Enter the number of items to be in the list:");
            String s=bf.readLine();
			x=Integer.parseInt(s);
			list1.get_num(x);
			list1.prepare_list();
            System.out.println("Press any digit to continue.");
            x=Integer.parseInt(bf.readLine());
			break;
        }
		case 2:
			list1.update_list();
            System.out.println("Press any digit to continue.");
            x=Integer.parseInt(bf.readLine());
			break;
		case 3:
			list1.disp_list(0);
            System.out.println("Press any digit to continue.");
            x=Integer.parseInt(bf.readLine());
			break;
		case 4:
            {
                order o=new order();
                o.collect_order(list1);
                o.create_bill(list1);
                ch=0;
                o.display_bill(list1);
                System.out.println("Press any digit to continue.");
            x=Integer.parseInt(bf.readLine());
                break;
            }
		case 5:
        {
            System.out.println("Enter item code.");
            String code=bf.readLine();
            int i=list1.find_code(code,list1.n_items+1);
            if(i!=-1)
            {
                System.out.println("Price: "+ list1.l1[i].ret_price()+"\n");
            }
            else{
                System.out.println("Item with that code doesn't exist.\n");
            }
            System.out.println("Press any digit to continue.");
            x=Integer.parseInt(bf.readLine());
            break;
        }
        case 6:
        {
            double pr=0;
            System.out.print("Enter amount:");
            pr=Double.parseDouble(bf.readLine());
            list1.disp_list(pr);
            System.out.println("Press any digit to continue.");
            x=Integer.parseInt(bf.readLine());
			break;
        }
        case 7:
            return;
	}
	}
}
/*function to manage the activities of the salesman */
static void User() throws IOException
{
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	while(true)
	{
        int choice;
        System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println("\t\t\tELECTRONICS WORLD\n");
        System.out.println("\n 1. Prepare an order.\n 2. See the price of an item.\n 3. See the items that costs more than a specified amount.\n 4. Exit");
        choice = Integer.parseInt(bf.readLine());
        switch(choice)
        {
            case 1:
                {
                    order o=new order();
                    o.collect_order(list1);
                    o.create_bill(list1);
                    o.display_bill(list1);
                    break;
                }
            case 2:
            {
                System.out.println("Enter item code.");
                String code=bf.readLine();
                int i=list1.find_code(code,list1.n_items+1);
                if(i!=-1)
                {
                    System.out.print("Price: "+ list1.l1[i].ret_price());
                }
                else{
                    System.out.println("Item with that code doesn't exist.");
                }
                break;
            }
            case 3:
            {
                double pr=0;
                System.out.print("Enter amount:");
                pr=Double.parseDouble(bf.readLine());
                list1.disp_list(pr);
                System.out.println("Press any digit to continue.");
                int x=Integer.parseInt(bf.readLine());
                break;
            }
            case 4:
                return;
        }
	}
}
/*main function to display the access panel and to call the necessary function */
public static void main(String[] args) throws IOException
{
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	int choice=1;
	String pswd;
    int i=0;
	do
	{
        System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println("\t\t\tELECTRONICS WORLD\n");
        if(i!=0)
        {
            System.out.println("Enter the mode of access.\n\n 1. Stock Entry Operator.\n 2. Shopkeeper.\n 3. Exit");
            choice = Integer.parseInt(bf.readLine());
        }i++;
		switch(choice)
		{
			case 1:
            {
                EraserThread et=new EraserThread("Enter the password");
                Thread hide=new Thread(et);
                hide.start();
				pswd = bf.readLine();
				if(pswd.equals(pass))
                {
                    hide.stop();
				    Admin();
                }
				else 
                System.out.println("Wrong Password!!!\n");
                if(hide.isAlive()) hide.stop();
				break;
            }
			case 2:
				User();
				break;
			case 3:
                return;
            default:
                System.out.println("Error Input!!!\nTry Again.");
		}
	}while(true);
}
}
