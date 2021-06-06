--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:36:43 04/25/2021
-- Design Name:   
-- Module Name:   /home/lp2917/14.7/ISE_DS/ASS2/ass2_2bb_test_bench.vhd
-- Project Name:  ASS2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ass2_2bb
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
 
ENTITY ass2_2bb_test_bench IS
END ass2_2bb_test_bench;
 
ARCHITECTURE behavior OF ass2_2bb_test_bench IS
 
    COMPONENT ass2_2bb
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         Y : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;

   signal X : std_logic_vector(3 downto 0) := (others => '0');
   signal Y : std_logic_vector(1 downto 0);
BEGIN
 
   uut: ass2_2bb PORT MAP (
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
		X <= "0000";
		wait for 1 ps;
   end process;

END;
