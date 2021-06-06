
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.Comparator.ALL;

entity mag_comp_4bit is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           o1 : out  STD_LOGIC;
           o2 : out  STD_LOGIC;
           o3 : out  STD_LOGIC);
end mag_comp_4bit;

architecture Behavioral of mag_comp_4bit is
begin
	p1: process(a, b)
		variable t1, t2, t3: std_logic;
	begin
		proc: comparator_4bit(a, b, t1, t2, t3);
		o1 <= t1;
		o2 <= t2;
		o3 <= t3;
	end process;
end Behavioral;

