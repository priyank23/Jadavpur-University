
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.Adder.ALL;

entity bcd_adder is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           sum : out  STD_LOGIC_VECTOR (4 downto 0));
end bcd_adder;

architecture Behavioral of bcd_adder is
begin
	
	p1: process(a, b)
		variable s: std_logic_vector(4 downto 0); 
	begin
		proc: bcd_adder_proc(a, b, s);
		sum <= s;
	end process;

end Behavioral;

