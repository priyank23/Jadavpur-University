
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass2_annex2b is
    Port ( X : in  STD_LOGIC_VECTOR (15 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end ass2_annex2b;

architecture Behavioral of ass2_annex2b is
procedure mux4x2(x:in std_logic_vector; y:out std_logic_vector) is
variable a: std_logic_vector(1 downto 0);
begin
		if x = "0001" then
			a := "00";
		elsif x = "0010" then
			a := "01";
		elsif x = "0100" then
			a := "10";
		elsif x = "1000" then
			a := "11";
		else
			a := "ZZ";
		end if;
		y := a;
end procedure;

begin

	p1: process(X)
	variable j,k: integer;
	variable a: std_logic_vector(7 downto 0);
	variable q: std_logic_vector(1 downto 0);
	variable p: std_logic_vector(3 downto 0);
	begin
		for k in 0 to 3 loop
			proc1: mux4x2(X(4*k+3 downto 4*k), a(2*k+1 downto 2*k));
			p(k) := '0';
			for j in 0 to 3 loop
				p(k) := p(k) or X(4*k+j);
			end loop;
		end loop;
		proc2: mux4x2(p, q);
		if q = "ZZ" then
			Y <= "ZZZZ";
		else
			for k in 0 to 3 loop
				if p(k) = '1' then
					if a(2*k+1 downto 2*k) = "ZZ" then
						Y <= "ZZZZ";
					else
						Y <= q & a(2*k+1 downto 2*k);
					end if;
				end if;
			end loop;
		end if;
	end process;

end Behavioral;

