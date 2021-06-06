
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.Comparator.ALL;

entity mag_comp_2bit is
    Port ( a : in  STD_LOGIC_VECTOR (1 downto 0);
           b : in  STD_LOGIC_VECTOR (1 downto 0);
           o1 : out  STD_LOGIC; -- A>B
           o2 : out  STD_LOGIC; -- A=B
           o3 : out  STD_LOGIC); -- A<B
end mag_comp_2bit;

architecture Behavioral of mag_comp_2bit is
begin
	p1: process(a, b)
		variable t1, t2, t3: std_logic;
	begin
		proc: comparator_2bit(a, b, t1, t2, t3);
		o1 <= t1;
		o2 <= t2;
		o3 <= t3;
	end process;
end Behavioral;

