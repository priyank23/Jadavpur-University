
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY ass3_2_1a_test_bench IS
END ass3_2_1a_test_bench;
 
ARCHITECTURE behavior OF ass3_2_1a_test_bench IS 
 
    COMPONENT ass3_2_1a
    PORT(
         X : IN  std_logic_vector(1 downto 0);
			e: IN std_logic;
         Y : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    
   signal X : std_logic_vector(1 downto 0);
	signal e : std_logic;
   signal Y : std_logic_vector(3 downto 0);
 
BEGIN
   uut: ass3_2_1a PORT MAP (
          X => X,
			 e => e,
          Y => Y
        );

   stim_proc: process
   begin		
		e<='0';
		X <= "00";
		wait for 1ps;
		e <= '1';
		X <= "00";
		wait for 1ps;
		X <= "01";
		wait for 1ps;
		X <= "10";
		wait for 1ps;
		X <= "11";
		wait for 1ps;
   end process;

END;
