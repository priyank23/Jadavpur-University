
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
-------------------
-- 2x4 decoder
-- select when statements
-------------------

entity ass3_2_1bd is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end ass3_2_1bd;

architecture Behavioral of ass3_2_1bd is
begin
with X select Y <=
	"0001" when "00",
	"0010" when "01",
	"0100" when "10",
	"1000" when "11",
	"ZZZZ" when others;

end Behavioral;
