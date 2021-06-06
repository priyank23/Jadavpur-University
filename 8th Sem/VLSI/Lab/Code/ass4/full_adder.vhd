
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.Adder.all;

entity full_adder is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           carry : out  STD_LOGIC);
end full_adder;

architecture Behavioral of full_adder is
begin
	p1: process(a, b, c)
	variable s, c_out: std_logic;
	begin
		proc: full_adder_proc(a, b, c, c_out, s);
		sum <= s;
		carry <= c_out;
	end process;
end Behavioral;

