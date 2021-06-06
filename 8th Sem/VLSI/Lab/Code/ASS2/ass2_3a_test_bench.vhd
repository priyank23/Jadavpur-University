
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY ass2_3a_test_bench IS
END ass2_3a_test_bench;
 
ARCHITECTURE behavior OF ass2_3a_test_bench IS 
 
    COMPONENT ass2_3a
    PORT(
         X : IN  std_logic_vector(7 downto 0);
         Y : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;

   signal X : std_logic_vector(7 downto 0) := (others => '0');
   signal Y : std_logic_vector(2 downto 0);
 
BEGIN
 
   uut: ass2_3a PORT MAP (
          X => X,
          Y => Y
        );
 
   -- Stimulus process
   stim_proc: process
   begin		
      X <= "00000001";
		wait for 1 ps;
		X <= "00000010";
		wait for 1 ps;
		X <= "00000100";
		wait for 1 ps;
		X <= "00001000";
		wait for 1 ps;
		X <= "00010000";
		wait for 1 ps;
		X <= "00100000";
		wait for 1 ps;
		X <= "01000000";
		wait for 1 ps;
		X <= "10000000";
		wait for 1 ps;
   end process;

END;
