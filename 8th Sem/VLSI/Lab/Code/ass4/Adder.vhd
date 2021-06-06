
library IEEE;
use IEEE.STD_LOGIC_1164.all;

package Adder is
	procedure half_adder_proc(a: in std_logic; b: in std_logic; c: out std_logic; s: out std_logic);
	procedure dec_to_bin_proc(decimal: in integer; num_of_bits: in integer; binary: out std_logic_vector);
	procedure full_adder_proc(a: in std_logic; b: in std_logic; c: in std_logic; carry: out std_logic; sum: out std_logic);
	procedure ripple_carry_adder_4bit_proc(a: in std_logic_vector; b: in std_logic_vector; c: in std_logic; s: out std_logic_vector);
	procedure adder_subtractor_proc(a: in std_logic_vector; b: in std_logic_vector; c: in std_logic; s: out std_logic_vector);
	procedure bcd_adder_proc(a: in std_logic_vector; b: in std_logic_vector; s: out std_logic_vector);
end Adder;

package body Adder is

	procedure half_adder_proc(a: in std_logic; b: in std_logic; c: out std_logic; s: out std_logic) is
	begin
		s:= a xor b;
		c:= a and b;
	end procedure;
	
	procedure dec_to_bin_proc(decimal: in integer; num_of_bits: in integer; binary: out std_logic_vector) is
		variable dec, bit_pos: integer;
	begin
		dec := decimal;
		bit_pos := 0;
		while(bit_pos < num_of_bits) loop
			if (dec rem 2) = 0 then
				binary(bit_pos) := '0';
			else
				binary(bit_pos) := '1';
			end if;
			dec := dec/2;
			bit_pos := bit_pos + 1;
		end loop;
	end procedure;
	
	procedure full_adder_proc(a: in std_logic; b: in std_logic; c: in std_logic; carry: out std_logic; sum: out std_logic) is
		variable c1, s1, c2, s2: std_logic;
	begin
		proc1: half_adder_proc(b, c, c1, s1);
		proc2: half_adder_proc(a, s1, c2, s2);
		carry := c1 or c2;
		sum := s2;
	end procedure;
 
	procedure ripple_carry_adder_4bit_proc(a: in std_logic_vector; b: in std_logic_vector; c: in std_logic; s: out std_logic_vector) is
		variable c1, s1: std_logic_vector(4 downto 0);
		variable k: integer;
	begin
		c1(0) := c;
		for k in 0 to 3 loop
			proc: full_adder_proc(a(k), b(k), c1(k), c1(k+1), s1(k));
		end loop;
		s1(4) := c1(4);
		s := s1;
	end procedure;
	
	procedure adder_subtractor_proc(a: in std_logic_vector; b: in std_logic_vector; c: in std_logic; s: out std_logic_vector) is
		variable p: std_logic_vector(3 downto 0);
		variable s1: std_logic_vector(4 downto 0);
	begin
		p(3 downto 0) := b(3 downto 0) xor (c & c & c & c);	
		proc: ripple_carry_adder_4bit_proc(a(3 downto 0), p(3 downto 0), c, s1(4 downto 0));
		if c = '1' then
			s1(4) := not s1(4);
		end if;
		s := s1;
	end procedure;
	
	procedure bcd_adder_proc(a: in std_logic_vector; b: in std_logic_vector; s: out std_logic_vector) is
		variable p: std_logic_vector(4 downto 0);
		variable z,c: std_logic;
		variable q: std_logic_vector(3 downto 0);
	begin
		c := '0';
		proc0: ripple_carry_adder_4bit_proc(a(3 downto 0), b(3 downto 0), c, p(4 downto 0));
		z := p(4) or (p(3) and (p(2) or p(1)));
		q := c & z & z & c;
		proc1: ripple_carry_adder_4bit_proc(p(3 downto 0), q(3 downto 0), c, s(4 downto 0));
		s(4) := z;
	end procedure;
end Adder;
