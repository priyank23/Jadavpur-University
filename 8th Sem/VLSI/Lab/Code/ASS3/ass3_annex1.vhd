
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_annex1 is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (15 downto 0));
end ass3_annex1;

architecture Behavioral of ass3_annex1 is
component ass3_2_1a is -- 2x4 decoder
	port(X: in  std_logic_vector(1 downto 0);
		  e: in std_logic;
		  Y: out std_logic_vector(3 downto 0));
end component;
signal a: std_logic_vector(3 downto 0);
begin
	c1: ass3_2_1a port map(X(3 downto 2), '1', a);

	gen: for i in 0 to 3 generate
		c2: ass3_2_1a port map(X(1 downto 0), a(i), Y(4*i+3 downto 4*i));
	end generate gen;
end Behavioral;

