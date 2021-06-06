
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass2_4 is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (2 downto 0));
end ass2_4;

architecture Behavioral of ass2_4 is
	component ass2_2ba is 
		PORT( X: IN STD_LOGIC_VECTOR(3 downto 0);
				Y: OUT STD_LOGIC_VECTOR(1 downto 0));
	end component;
	component encoder2x1 is 
		PORT( X: IN STD_LOGIC_VECTOR(1 downto 0);
				Y: OUT STD_LOGIC);
	end component;
	
	signal a,b,p: STD_LOGIC_VECTOR(1 downto 0);
	signal q: STD_LOGIC;
	
begin
c1: ass2_2ba port map(X(3 downto 0), a);
c2: ass2_2ba port map(X(7 downto 4), b);
c3: encoder2x1 port map(p, q);

p(0) <= X(0) or X(1) or X(2) or X(3);
p(1) <= X(4) or X(5) or X(6) or X(7);

p1: process(X, p, q, a, b)
begin
	if X(7 downto 4) = "0000" then
		Y <= q & a;
	elsif X(3 downto 0) = "0000" then
		Y <= q & b;
	else
		Y <= "ZZZ";
	end if;
end process;

end Behavioral;