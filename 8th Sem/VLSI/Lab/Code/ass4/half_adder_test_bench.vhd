-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE work.Adder.ALL;

ENTITY half_adder_test_bench IS
END half_adder_test_bench;

ARCHITECTURE behavior OF half_adder_test_bench IS 

-- Component Declaration
		 COMPONENT half_adder
		 PORT(
				  a : in  STD_LOGIC;
				  b : in  STD_LOGIC;
				  sum : out  STD_LOGIC;
				  carry : out  STD_LOGIC
					);
		 END COMPONENT;

		 SIGNAL a :  std_logic;
		 SIGNAL b :  std_logic;
		 SIGNAL sum: std_logic;
		 SIGNAL carry: std_logic;
		 
BEGIN
	uut: half_adder PORT MAP (
          a => a,
          b => b,
			 sum => sum,
			 carry => carry
        );
		  
	tb : PROCESS
	BEGIN
			a <= '0';
			b <= '0';
			wait for 1ps;
			a <= '0';
			b <= '1';
			wait for 1ps;
			a <= '1';
			b <= '0';
			wait for 1ps;
			a <= '1';
			b <= '1';
			wait for 1ps;
	END PROCESS tb;
	
END;
