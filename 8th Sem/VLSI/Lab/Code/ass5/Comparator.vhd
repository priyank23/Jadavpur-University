
library IEEE;
use IEEE.STD_LOGIC_1164.all;

package Comparator is
	procedure comparator_2bit(a:in std_logic_vector; b: in std_logic_vector; o1: out std_logic; o2: out std_logic; o3: out std_logic);
	procedure comparator_4bit(a:in std_logic_vector; b: in std_logic_vector; o1: out std_logic; o2: out std_logic; o3: out std_logic);
	procedure dec_to_bin(decimal: in integer; num_of_bits: in integer; binary: out std_logic_vector);
end Comparator;

package body Comparator is

	procedure comparator_2bit(a:in std_logic_vector; b: in std_logic_vector; o1: out std_logic; o2: out std_logic; o3: out std_logic) is
	begin
		o1 := (a(1) and not b(1)) or (a(0) and not b(1) and not b(0)) or (a(1) and a(0) and not b(0));
		o2 := (a(0) xnor b(0)) and (a(1) xnor b(1));
		o3 := (not a(1) and b(1)) or (not a(0) and b(1) and b(0)) or (not a(1) and not a(0) and b(0));
	end procedure;
	
	procedure comparator_4bit(a:in std_logic_vector; b: in std_logic_vector; o1: out std_logic; o2: out std_logic; o3: out std_logic) is
		variable lsb1, lsb2, lsb3, msb1, msb2, msb3: std_logic;
	begin
		proc1: comparator_2bit(a(3 downto 2), b(3 downto 2), msb1, msb2, msb3);
		proc2: comparator_2bit(a(1 downto 0), b(1 downto 0), lsb1, lsb2, lsb3);
		
		if msb2 = '0' then
			o1 := msb1;
			o2 := msb2;
			o3 := msb3;
		elsif msb2 = '1' then
			o1 := lsb1;
			o2 := lsb2;
			o3 := lsb3;
		end if;
	end procedure;

	procedure dec_to_bin(decimal: in integer; num_of_bits: in integer; binary: out std_logic_vector) is
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
end Comparator;
