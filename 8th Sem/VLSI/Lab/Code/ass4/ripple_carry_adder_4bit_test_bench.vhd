--------------------------------------------------------------------------------
-- Company: 
-- Engineer:

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE work.Adder.ALL;
 
ENTITY ripple_carry_adder_4bit_test_bench IS
END ripple_carry_adder_4bit_test_bench;
 
ARCHITECTURE behavior OF ripple_carry_adder_4bit_test_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ripple_carry_adder_4bit
    PORT(
         a : IN  std_logic_vector(3 downto 0);
         b : IN  std_logic_vector(3 downto 0);
			c : IN  std_logic;
         sum : OUT  std_logic_vector(4 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal a : std_logic_vector(3 downto 0) := (others => '0');
   signal b : std_logic_vector(3 downto 0) := (others => '0');
	signal c : std_logic;
 	--Outputs
   signal sum : std_logic_vector(4 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
  
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ripple_carry_adder_4bit PORT MAP (
          a => a,
          b => b,
			 c => c,
          sum => sum
        );

   -- Stimulus process
   stim_proc: process
		variable j,k: integer;
		variable bin_a, bin_b: std_logic_vector(3 downto 0);
   begin
		for j in 0 to 15 loop
			proc_a: dec_to_bin_proc(j, 4, bin_a);
			a <= bin_a;
			for k in 0 to 15 loop
				proc_b: dec_to_bin_proc(k, 4, bin_b);
				b <= bin_b;
				c <= '0';
				wait for 1ps;
			end loop;
		end loop;
   end process;

END;
