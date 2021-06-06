
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass2_1d is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC);
end ass2_1d;

architecture Behavioral of ass2_1d is
begin
	with X select
		Y <= '0' when "01",
		     '1' when "10",
			  'Z' when others;
end Behavioral;
