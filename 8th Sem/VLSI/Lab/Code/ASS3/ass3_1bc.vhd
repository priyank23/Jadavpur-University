
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_1bc is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end ass3_1bc;

architecture Behavioral of ass3_1bc is
begin
Y <= 
	"01" when X = '0' else
	"10" when X = '1';
end Behavioral;

