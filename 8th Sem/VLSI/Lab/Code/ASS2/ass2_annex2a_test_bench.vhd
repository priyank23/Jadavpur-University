--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   21:52:36 05/09/2021
-- Design Name:   
-- Module Name:   /home/lp2917/14.7/ISE_DS/ASS2/ass2_annex2a_test_bench.vhd
-- Project Name:  ASS2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ass2_annex2a
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ass2_annex2a_test_bench IS
END ass2_annex2a_test_bench;
 
ARCHITECTURE behavior OF ass2_annex2a_test_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ass2_annex2a
    PORT(
         X : IN  std_logic_vector(15 downto 0);
         Y : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(15 downto 0);

 	--Outputs
   signal Y : std_logic_vector(3 downto 0);

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ass2_annex2a PORT MAP (
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
