
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass2_3b is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (2 downto 0));
end ass2_3b;

architecture Behavioral of ass2_3b is
begin
	with X select
		Y <= "000" when "00000001",
		     "001" when "00000010",
			  "010" when "00000100",
			  "011" when "00001000",
			  "100" when "00010000",
			  "101" when "00100000",
			  "110" when "01000000",
			  "111" when "10000000",
			  "ZZZ" when others;
end Behavioral;

