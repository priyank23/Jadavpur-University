
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.Adder.ALL;

entity adder_subtractor is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           c : in  STD_LOGIC;
           sum : out  STD_LOGIC_VECTOR (4 downto 0));
end adder_subtractor;

architecture Behavioral of adder_subtractor is
begin
	p1: process(a, b, c)
		variable s: std_logic_vector(4 downto 0);
	begin
		proc: adder_subtractor_proc(a, b, c, s);
		sum <= s;
	end process;
end Behavioral;

