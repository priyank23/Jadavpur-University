
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
------------------
-- 2x4 decoders
-- ase statements
------------------
entity ass3_2_1_bb is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           X : out  STD_LOGIC_VECTOR (3 downto 0));
end ass3_2_1_bb;

architecture Behavioral of ass3_2_1_bb is
begin
p1: process(X)
begin
	case X is
		when "00" => Y <= "0001";
		when "01" => Y <= "0010";
		when "10" => Y <= "0100";
		when "11" => Y <= "1000";
		when others => Y <= "ZZZZ";
	end case;
end process;
end Behavioral;

