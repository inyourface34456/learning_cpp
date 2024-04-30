sub line {
	my ($start_char, $chars) = @_;

	my $out = "";

	for (my $o = 0; $o < $chars; ++$o) {
		last if $start_char + $o > 0xff;
		$out .= chr($start_char + $o) . " ";
	}

	$out
}

sub sg_line {
	"\e)2\x0e" . &line(@_) . "\x0f";
}

my $chars_per_line=16;

for (my $ch = 0; $ch < 256; $ch+=$chars_per_line) {
	print &line($ch, $chars_per_line),
		"\n",
		&sg_line($ch, $chars_per_line),
		"\n";
}
