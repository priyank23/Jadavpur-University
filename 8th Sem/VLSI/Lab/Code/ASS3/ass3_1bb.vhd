
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_1bb is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end ass3_1bb;

architecture Behavioral of ass3_1bb is
begin
p1: process(X)
begin
	case X is
		when '0' => Y <= "01";
		when '1' => Y <= "10";
		when others => Y <= "ZZ";
	end case;
end process;
end Behavioral;
