
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY ass2_5_test_bench IS
END ass2_5_test_bench;
 
ARCHITECTURE behavior OF ass2_5_test_bench IS 
 
    COMPONENT ass2_5
    PORT(
         X : IN  std_logic_vector(15 downto 0);
         Y : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    
   signal X : std_logic_vector(15 downto 0) := (others => '0');
   signal Y : std_logic_vector(3 downto 0);
 
BEGIN
 
   uut: ass2_5 PORT MAP (
          X => X,
          Y => Y
        );
 
   stim_proc: process
   begin		
		X <= "0000000000000000";
		wait for 1 ps;
		for i in 0 to 15 loop
			X(i) <= '1';
			wait for 1ps;
			X(i) <= '0';
		end loop;
   end process;

END;
