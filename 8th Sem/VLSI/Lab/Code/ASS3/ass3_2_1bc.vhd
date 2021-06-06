
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--------------------
-- 2x4 decoder 
-- when else statements
--------------------

entity ass3_2_1bc is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end ass3_2_1bc;

architecture Behavioral of ass3_2_1bc is
begin
Y <=  "0001" when X = "00" else
		"0010" when X = "01" else
		"0100" when X = "10" else
		"1000" when X = "11" else
		"ZZZZ";

end Behavioral;

