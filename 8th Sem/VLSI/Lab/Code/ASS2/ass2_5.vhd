
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass2_5 is
    Port ( X : in  STD_LOGIC_VECTOR (15 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end ass2_5;

architecture Behavioral of ass2_5 is
component ass2_2ba is
	port( X: in STD_LOGIC_VECTOR (3 downto 0);
			Y: out STD_LOGIC_VECTOR(1 downto 0));
end component;
signal a,b,c,d,q: STD_LOGIC_VECTOR(1 downto 0);
signal p: STD_LOGIC_VECTOR(3 downto 0);

begin
	p(3) <= X(15) or X(14) or X(13) or X(12);
	p(2) <= X(11) or X(10) or X(9) or X(8);
	p(1) <= X(7) or X(6) or X(5) or X(4);
	p(0) <= X(3) or X(2) or X(1) or X(0);

	c1: ass2_2ba port map(X(15 downto 12), a);
	c2: ass2_2ba port map(X(11 downto 8), b);
	c3: ass2_2ba port map(X(7 downto 4), c);
	c4: ass2_2ba port map(X(3 downto 0), d);
	c5: ass2_2ba port map(p, q);

	p1: process(X, a, b, c, d, q, p)
	begin
		if X(11 downto 0) = "000000000000" then
			Y <= q & a;
		elsif X(15 downto 12) = "0000" and X(7 downto 0) = "00000000" then
			Y <= q & b;
		elsif X(15 downto 8) = "00000000" and X(3 downto 0) = "0000" then
			Y <= q & c;
		elsif X(15 downto 4) = "000000000000" then
			Y <= q & d;
		else
			Y <= "ZZZZ";
		end if;
	end process;
end Behavioral;

