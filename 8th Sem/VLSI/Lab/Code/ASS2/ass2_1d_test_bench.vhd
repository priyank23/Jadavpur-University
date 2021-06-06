
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY ass2_1d_test_bench IS
END ass2_1d_test_bench;
 
ARCHITECTURE behavior OF ass2_1d_test_bench IS 
 
    COMPONENT ass2_1d
    PORT(
         X : IN  std_logic_vector(1 downto 0);
         Y : OUT  std_logic
        );
    END COMPONENT;
   signal X : std_logic_vector(1 downto 0) := (others => '0');
   signal Y : std_logic;

 
BEGIN

   uut: ass2_1d PORT MAP (
          X => X,
          Y => Y
        );

   -- Stimulus process
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
