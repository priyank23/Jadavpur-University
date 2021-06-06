
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_1bd is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end ass3_1bd;

architecture Behavioral of ass3_1bd is
begin
with X select Y <=
	"01" when '0',
	"10" when '1';

end Behavioral;

