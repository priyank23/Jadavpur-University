
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_2_1a is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
			  e : in STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end ass3_2_1a;

-- 2x4 demux using gate level modelling
architecture Behavioral of ass3_2_1a is
begin
	Y(0) <= e and ((not X(1)) and (not X(0)));
	Y(1) <= e and ((not X(1)) and X(0));
	Y(2) <= e and (X(1) and (not X(0)));
	Y(3) <= e and (X(1) and X(0));
	
end Behavioral;

