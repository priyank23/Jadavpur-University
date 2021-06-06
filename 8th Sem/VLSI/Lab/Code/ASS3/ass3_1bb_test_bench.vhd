--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   00:21:16 05/08/2021
-- Design Name:   
-- Module Name:   /home/lp2917/14.7/ISE_DS/ASS3/ass3_1bb_test_bench.vhd
-- Project Name:  ASS3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ass3_1bb
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
 
ENTITY ass3_1bb_test_bench IS
END ass3_1bb_test_bench;
 
ARCHITECTURE behavior OF ass3_1bb_test_bench IS 

    COMPONENT ass3_1bb
    PORT(
         X : IN  std_logic;
         Y : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    
   signal X : std_logic := '0';
   signal Y : std_logic_vector(1 downto 0);
 
BEGIN
 
   uut: ass3_1bb PORT MAP (
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
