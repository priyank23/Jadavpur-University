
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY ass2_2a_test_bench IS
END ass2_2a_test_bench;
 
ARCHITECTURE behavior OF ass2_2a_test_bench IS 
 
    COMPONENT ass2_2a
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         Y : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;

   signal X : std_logic_vector(3 downto 0) := (others => '0');
   signal Y : std_logic_vector(1 downto 0);

 
BEGIN

   uut: ass2_2a PORT MAP (
          X => X,
          Y => Y
        );

   -- Stimulus process
   stim_proc: process
   begin		
      X <= "0001";
		wait for 1 ps;
		X <= "0010";
		wait for 1 ps;
		X <= "0100";
		wait for 1 ps;
		X <= "1000";
		wait for 1 ps;
   end process;

END;
