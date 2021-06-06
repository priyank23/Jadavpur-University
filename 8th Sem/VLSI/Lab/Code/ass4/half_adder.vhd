
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.ADDER.ALL;

entity half_adder is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           carry : out  STD_LOGIC);
end half_adder;

architecture Behavioral of half_adder is
begin
	p1: process(a, b)
	variable c,s: std_logic;
	begin
		proc: half_adder_proc(a, b, c, s);
		carry <= c;
		sum <= s;
	end process;
end Behavioral;

