function myFunction() {
  var ss = SpreadsheetApp.openById("1F5OpWnIcFwkRaZA59ozVcXt1dJR0tHDjqAiWe32Fiqo");
  SpreadsheetApp.setActiveSpreadsheet(ss);
  var label = GmailApp.getUserLabelByName("TMT");
  var threads = label.getThreads();
  
  for (var i=0; i<threads.length; i++)
  {
    var styles = ['(Classic)', '(Pita)', '(Trad X)', '(Single Twist)', '(Stanwick)', '(O-Channel)', '(Release)', '(Ladder)'];
    var saddles = ['(None)', '(Closed)', '(Open)'];
    var colors = ['(White)', '(Black)'];
    var tmp,
      message = threads[i].getMessages()[0],
      subject = message.getSubject(),
      content = message.getPlainBody();
    var dat = message.getDate();
    if(subject)
    {
       tmp = subject.match(/([0-9]+)/);
       var num = (tmp && tmp[1]) ? tmp[1].trim() : 'No username';
    }
    if(content)
    {
      tmp = content.match(/(\d{1,3}\.\d{1,2})/);
      var price = (tmp && tmp[1]) ? tmp[1].trim() : 'Null';
      var basic = content.match(/(Single String Basics)/);
      if(basic)
      {
        var opt = 'Basic';
      }
      else
      {
        var opt = 'Custom';
      }
      var key = 'SHIPPING TO:';
      var name = findNext(key, content);
      var street = findNext(name, content);
      var add = findNext(street, content);
      var ctry = findNext(add, content);
      var cc = findNext(ctry, content);
      var email = findNext(cc, content);
      var phone = findNext(email, content);
      if(phone == name) phone = 'Null';
      for (var j=0; j<8; j++){
        if(find(styles[j], content) != 'Null')
        {
          var style = find(styles[j], content);
        }
      }
      for (var k=0; k<3; k++){
        if(find(saddles[k], content) != 'Null'){
          var sad = find(saddles[k], content);
          break;
        }
        else
          var sad = 'None';
      }
      var key5 = 'Inner Leathers:';
      var il = findNext(key5, content);
      var key6 = 'Outer Leathers:';
      var ol = findNext(key6, content);
      var key7 = 'Top String:';
      var ts = findNext(key7, content);
      var key8 = 'Sidewalls:';
      var sw = findNext(key8, content);
      if(style == 'Release')
      {
         var key2 = 'Rung Color:';
         var cl1 = findNext(key2, content);
         var key3 = 'Crosslace Color:';
         var cl2 = findNext(key3, content);
         var key4 = 'Another Crosslace Color:';
         var cl3 = findNext(key4, content);
         if(cl3 == 'Location:')
         {
           cl3 = 'Null';
         }
      }
       else if(style == 'Ladder')
      {
         var key2 = 'Rung Color:';
         var cl1 = findNext(key2, content);
         var key3 = 'Crosslace Color:';
         var cl2 = findNext(key3, content);
         var key4 = 'Another Crosslace Color:';
         var cl3 = findNext(key4, content);
         if(cl3 == 'Last Crosslace Color:')
         {
           cl3 = 'Null';
         }
      }
      else
      {
        var key2 = 'Crosslace Color:';
        var cl1 = findNext(key2, content);
        if(cl1 == 'Null')
        {
          if(content.match(/(White)/)){
            cl1 = 'White';
            cl2 = 'White';
            cl3 = 'White';
            ol = 'White';
            il = 'White';
            ts = 'White';
            sw = 'White';
          }
          else {
            cl1 = 'Black';
            cl2 = 'Black';
            cl3 = 'Black';
            ol = 'Black';
            il = 'Black';
            ts = 'Black';
            sw = 'Black';
          }
        }
        var key3 = 'Another Crosslace Color:';
        var cl2 = findNext(key3, content);
        if(cl2 == 'Last Crosslace Color:')
        {
          cl2 = 'Null';
        }
        var key4 = 'Last Crosslace Color:';
        var cl3 = findNext(key4, content);
        if(cl3 == 'Location:')
        {
          cl3 = 'Null';
        }
      }
    }
      ss.appendRow([num, dat, name, street, add, ctry, email, phone, price, opt, style, sad, cl1, cl2, cl3, il, ol, ts, sw]);
      threads[i].removeLabel(label);
  }
  }
function findNext(search, content){
     var reg = search + '([\r\n]+([^\r\n]+))';
     var regEx = new RegExp(reg);
     tmp = content.match(regEx);
     return (tmp && tmp[1]) ? tmp[1].trim() : 'Null';
}
function find(search, content){
     var regEx = new RegExp(search);
     tmp = content.match(regEx);
     return (tmp && tmp[1]) ? tmp[1].trim() : 'Null';
}

function doGet() {
  return HtmlService.createHtmlOutputFromFile('Client');
}

