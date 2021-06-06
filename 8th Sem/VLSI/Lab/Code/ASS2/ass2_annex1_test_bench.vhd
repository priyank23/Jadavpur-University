
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 

ENTITY ass2_annex1_test_bench IS
END ass2_annex1_test_bench;
 
ARCHITECTURE behavior OF ass2_annex1_test_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ass2_annex1
    PORT(
         X : IN  std_logic_vector(15 downto 0);
         Y : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(15 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(3 downto 0);
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ass2_annex1 PORT MAP (
          X => X,
          Y => Y
        );

 

   -- Stimulus process
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
