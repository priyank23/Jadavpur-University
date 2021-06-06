
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_1ba is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end ass3_1ba;

architecture Behavioral of ass3_1ba is
begin
p1: process(X)
begin
	if X = '0' then
		Y <= "01";
	else
		Y <= "10";
	end if;
end process;

end Behavioral;

