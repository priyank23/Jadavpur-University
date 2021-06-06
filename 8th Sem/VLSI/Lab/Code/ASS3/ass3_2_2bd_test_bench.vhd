
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY ass3_2_2bd_test_bench IS
END ass3_2_2bd_test_bench;
 
ARCHITECTURE behavior OF ass3_2_2bd_test_bench IS
 
    COMPONENT ass3_2_2bd
    PORT(
         X : IN  std_logic_vector(2 downto 0);
         Y : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
	 
   signal X : std_logic_vector(2 downto 0);
   signal Y : std_logic_vector(7 downto 0);
 
BEGIN

   uut: ass3_2_2bd PORT MAP (
          X => X,
          Y => Y
        );

   -- Stimulus process
   stim_proc: process
   begin		
      X <= "000";
		wait for 1ps;
		X <= "001";
		wait for 1ps;
		X <= "010";
		wait for 1ps;
		X <= "011";
		wait for 1ps;
		X <= "100";
		wait for 1ps;
		X <= "101";
		wait for 1ps;
		X <= "110";
		wait for 1ps;
		X <= "111";
		wait for 1ps;
   end process;

END;
