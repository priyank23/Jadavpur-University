
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE work.Adder.ALL;

ENTITY bcd_adder_test_bench IS
END bcd_adder_test_bench;
 
ARCHITECTURE behavior OF bcd_adder_test_bench IS 

 
    COMPONENT bcd_adder
    PORT(
         a : IN  std_logic_vector(3 downto 0);
         b : IN  std_logic_vector(3 downto 0);
         sum : OUT  std_logic_vector(4 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal a : std_logic_vector(3 downto 0) := (others => '0');
   signal b : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal sum : std_logic_vector(4 downto 0);
 
BEGIN

   uut: bcd_adder PORT MAP (
          a => a,
          b => b,
          sum => sum
        );
 
   -- Stimulus process
   stim_proc: process
		variable bin_a, bin_b: std_logic_vector(3 downto 0);
   begin		
      for i in 0 to 15 loop
			dec_to_bin_proc(i, 4, bin_a);
			a <= bin_a;
			for j in 0 to 15 loop
				dec_to_bin_proc(j, 4, bin_b);
				b <= bin_b;
				wait for 1ps;
			end loop;
		end loop;
   end process;

END;
