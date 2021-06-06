
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_4 is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (15 downto 0));
end ass3_4;

architecture Behavioral of ass3_4 is
component ass3_2_1a is 
	port(X: in  std_logic_vector(1 downto 0);
		  Y: out std_logic_vector(3 downto 0));
end component;
signal a,b: std_logic_vector(3 downto 0);
begin
	c1: ass3_2_1a port map(X(3 downto 2), a);
	c2: ass3_2_1a port map(X(1 downto 0), b);

p1: process(X, a, b)
begin
	if a(3) = '1' then
		Y <= b & "000000000000";
	elsif a(2) = '1' then
		Y <= "0000" & b & "00000000";
	elsif a(1) = '1' then
		Y <= "00000000" & b & "0000";
	else
		Y <= "000000000000" & b;
	end if;
end process;
end Behavioral;

