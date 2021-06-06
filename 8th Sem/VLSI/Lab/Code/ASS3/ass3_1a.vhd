
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_1a is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end ass3_1a;

architecture Behavioral of ass3_1a is
begin

Y(1) <= X;
Y(0) <= not X; 

end Behavioral;

