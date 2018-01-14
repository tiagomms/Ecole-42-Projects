#!/usr/bin/php
<?PHP

if (is_readable($argv[1]))
{
    $result = array();
    $html_text = file_get_contents($argv[1]);
    $html_text_length = strlen($html_text);
    $current = 0;
    
    # helpers
    
    function is_inside_html()
    {
        global $html_text_length, $current;
        return ($current < $html_text_length);
    }
    
    function get_current()
    {
        global $html_text, $current;
        return substr($html_text, $current, 1);
    }
    
    function compare_current($compare_to)
    {
        global $current, $html_text, $html_text_length;
        $length = strlen($compare_to);
        if ($current + $length > $html_text_length)
            return false;
        return strcasecmp(substr($html_text, $current, $length), substr($compare_to, 0, $length)) == 0;
    }
    
    function increment($number = 1)
    {
        global $result, $current;
        while ($number != 0)
        {
            array_push($result, get_current());
            $current += 1;
            $number -=1;
        }
    }
    
    function upcase_increment()
    {
        global $result, $current;
        array_push($result, strtoupper(get_current()));
        $current += 1;
    }
    
    # logic
    
    function parse_outer_tag()
    {
        parse_inside_tag();
        while (compare_current("</a>") == false && is_inside_html())
        {
            if (compare_current("<"))
                parse_inside_tag();
            else
 	           upcase_increment();
        }
        increment(4);
    }
    
    function parse_inside_tag()
    {
        while (get_current() !== ">" && is_inside_html())
        {
            if (compare_current("title=\"") == true)
            {
                increment(7);
                while (get_current() !== "\"")
                    upcase_increment();
            }
            increment();
        }
        increment();
    }
    
    # begin of 'main' code
    
    while ($current < $html_text_length)
    {
        if (compare_current("<a ") || compare_current("<a>"))
        {
            increment(2);
            parse_outer_tag();
        }
        increment(1);
    }
    
    $final_html = implode("", $result);
    
    echo "$final_html";
}

?>