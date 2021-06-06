
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_3 is
    Port ( X : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end ass3_3;

architecture Behavioral of ass3_3 is
component ass3_1a is
port (X: in std_logic;
			Y: out std_logic_vector(1 downto 0));
end component;
component ass3_2_1a is port(X: in  std_logic_vector(1 downto 0);
									  Y: out std_logic_vector(3 downto 0));
end component;
signal a: STD_LOGIC_VECTOR(1 downto 0);
signal q: STD_LOGIC_VECTOR(3 downto 0);
begin
c1: ass3_1a port map(X(2), a);
c2: ass3_2_1a port map(X(1 downto 0), q);

p1: process(X, a, q)
begin
	if a = "01" then
		Y <= "0000" & q;
	else 
		Y <= q & "0000";
	end if;
end process;
end Behavioral;

