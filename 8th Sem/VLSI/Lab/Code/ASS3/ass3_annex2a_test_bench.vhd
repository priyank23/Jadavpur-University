--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   21:49:20 05/09/2021
-- Design Name:   
-- Module Name:   /home/lp2917/14.7/ISE_DS/ASS3/ass3_annex2a_test_bench.vhd
-- Project Name:  ASS3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ass3_annex2a
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
 
ENTITY ass3_annex2a_test_bench IS
END ass3_annex2a_test_bench;
 
ARCHITECTURE behavior OF ass3_annex2a_test_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ass3_annex2a
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         Y : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(15 downto 0);
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ass3_annex2a PORT MAP (
          X => X,
          Y => Y
        );
		  
   -- Stimulus process
   stim_proc: process
   begin
      X <= "0000";
		wait for 1ps;
		X <= "0001";
		wait for 1ps;
		X <= "0010";
		wait for 1ps;
		X <= "0011";
		wait for 1ps;
		X <= "0100";
		wait for 1ps;
		X <= "0101";
		wait for 1ps;
		X <= "0110";
		wait for 1ps;
		X <= "0111";
		wait for 1ps;
		X <= "1000";
		wait for 1ps;
		X <= "1001";
		wait for 1ps;
		X <= "1010";
		wait for 1ps;
		X <= "1011";
		wait for 1ps;
		X <= "1100";
		wait for 1ps;
		X <= "1101";
		wait for 1ps;
		X <= "1110";
		wait for 1ps;
		X <= "1111";
		wait for 1ps;
   end process;

END;
