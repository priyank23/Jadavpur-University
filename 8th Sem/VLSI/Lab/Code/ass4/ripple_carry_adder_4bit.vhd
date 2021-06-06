
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.Adder.ALL;

entity ripple_carry_adder_4bit is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
			  c : in  STD_LOGIC;
           sum : out  STD_LOGIC_VECTOR (4 downto 0));
end ripple_carry_adder_4bit;

architecture Behavioral of ripple_carry_adder_4bit is
begin
	p1: process(a, b, c)
		variable s: std_logic_vector(4 downto 0);
	begin
		proc: ripple_carry_adder_4bit_proc(a, b, c, s);
		sum <= s;
	end process;

end Behavioral;

