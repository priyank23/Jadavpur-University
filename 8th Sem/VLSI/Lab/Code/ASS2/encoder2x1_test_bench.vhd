--------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY encoder2x1_test_bench IS
END encoder2x1_test_bench;
 
ARCHITECTURE behavior OF encoder2x1_test_bench IS 
 
    COMPONENT encoder2x1
    PORT(
         X : IN  std_logic_vector(1 downto 0);
         Y : OUT  std_logic
        );
    END COMPONENT;
    
   signal X : std_logic_vector(1 downto 0) := (others => '0');
   signal Y : std_logic;
 
BEGIN
   uut: encoder2x1 PORT MAP (
          X => X,
          Y => Y
        );
 
   stim_proc: process
   begin
	  X <= "01";
	  wait for 1 ps;
	  X <= "10";
	  wait for 1 ps;
	  X <= "11";
	  wait for 1 ps;
   end process;
END;