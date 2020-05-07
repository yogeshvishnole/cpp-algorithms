
function footer(copyright) {
    var today = new Date();
    var last_change = new Date(document.lastModified);
    // Change date to yyyy-mm-dd format
    var d = last_change.getDate(); // day of month
    var dd = ((d < 10)?"-0":"-") + d;
    var m = last_change.getMonth() + 1; // getMonth returns range 0..11
    var mm = ((m < 10)?"-0":"-") + m;
    var yyyymmdd = last_change.getFullYear() +  mm + dd;

    document.write("<div class='footer'>");
    
    if (copyright != "") {
        document.write("<a href=\"http://www.fredosaurus.com/copyleft.html\">Copyleft</a> " + copyright);
    }
    document.write(" <a href='../fred/index.html'>Fred Swartz</a>");
    document.write(" Last update " + yyyymmdd + ", ");
    document.write("URL=" + document.url);
    document.write("</div>");
}//endfunction

function setActiveStyleSheet(title) {
    var i, a;
    for (i=0; (a = document.getElementsByTagName("link")[i]); i++) {
        if (a.getAttribute("rel") &&
                a.getAttribute("rel").indexOf("style") != -1 &&
                a.getAttribute("title")) {
            a.disabled = (a.getAttribute("title") != title);
        }
    }
}
