
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY ass3_1ba_test_bench IS
END ass3_1ba_test_bench;
 
ARCHITECTURE behavior OF ass3_1ba_test_bench IS 
 
    COMPONENT ass3_1ba
    PORT(
         X : IN  std_logic;
         Y : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    
   signal X : std_logic := '0';
   signal Y : std_logic_vector(1 downto 0);
 
BEGIN
 
   uut: ass3_1ba PORT MAP (
          X => X,
          Y => Y
        );

   stim_proc: process
   begin		
      X <= '0';
		wait for 1ps;
		X <= '1';
		wait for 1ps;
   end process;

END;
