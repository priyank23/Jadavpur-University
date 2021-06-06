
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE work.DecimalToBinary.ALL;

ENTITY mag_comp_2bit_test_bench IS
END mag_comp_2bit_test_bench;
 
ARCHITECTURE behavior OF mag_comp_2bit_test_bench IS 

 
    COMPONENT mag_comp_2bit
    PORT(
         a : IN  std_logic_vector(1 downto 0);
         b : IN  std_logic_vector(1 downto 0);
         o1 : OUT  std_logic;
         o2 : OUT  std_logic;
         o3 : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal a : std_logic_vector(1 downto 0) := (others => '0');
   signal b : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal o1 : std_logic;
   signal o2 : std_logic;
   signal o3 : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mag_comp_2bit PORT MAP (
          a => a,
          b => b,
          o1 => o1,
          o2 => o2,
          o3 => o3
        );
 

   -- Stimulus process
   stim_proc: process
		variable bin_a, bin_b: std_logic_vector(1 downto 0); 
   begin		
      for i in 0 to 3 loop
			proca: dec_to_bin(i, 2, bin_a);
			a <= bin_a;
			for j in 0 to 3 loop
				procb: dec_to_bin(j, 2, bin_b);
				b <= bin_b;
				wait for 1ps;
			end loop;
		end loop;
   end process;

END;
