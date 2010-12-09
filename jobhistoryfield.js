$(document).ready(function() {

  var numboxes = $("input[type=checkbox]").length;

  for(var k=0; k < numboxes; k++) {
    if ($("#edit-field-app-job-history-"+k+"-currentjob").is(':checked')) {
      //~ $("#edit-field-resume-company-"+k+"-todate-month-wrapper").attr("style","display: none;");
      $("#edit-field-app-job-history-"+k+"-todate-month").attr("disabled","disabled");
      //~ $("#edit-field-resume-company-"+k+"-todate-year").attr("style","display: none;");
      $("#edit-field-app-job-history-"+k+"-todate-year").attr("disabled","disabled");
      //~ $("#edit-field-resume-company-"+k+"-todate-wrapper").attr("style","display: none;");
      $("#edit-field-app-job-history-"+k+"-todate-wrapper").attr("disabled","disabled");
    }
    else {
      //~ $("#edit-field-resume-company-"+k+"-todate-month-wrapper").attr("style","display: visible;");
      $("#edit-field-app-job-history-"+k+"-todate-month").removeAttr('disabled');
      //~ $("#edit-field-resume-company-"+k+"-todate-year").attr("style","display: visible;");
      $("#edit-field-app-job-history-"+k+"-todate-year").removeAttr('disabled');
      //~ $("#edit-field-resume-company-"+k+"-todate-wrapper").attr("style","display: visible;");
      $("#edit-field-app-job-history-"+k+"-todate-wrapper").removeAttr('disabled');
    }
  }

  $("input[type=checkbox]").click(function() {
    var numboxes = $("input[type=checkbox]").length;
    for(var k=0; k < numboxes; k++) {
      if ($("#edit-field-app-job-history-"+k+"-currentjob").is(':checked')) {
        //~ $("#edit-field-resume-company-"+k+"-todate-month-wrapper").attr("style","display: none;");
        $("#edit-field-app-job-history-"+k+"-todate-month").attr("disabled","disabled");
        //~ $("#edit-field-resume-company-"+k+"-todate-year").attr("style","display: none;");
        $("#edit-field-app-job-history-"+k+"-todate-year").attr("disabled","disabled");
        //~ $("#edit-field-resume-company-"+k+"-todate-wrapper").attr("style","display: none;");
        $("#edit-field-app-job-history-"+k+"-todate-wrapper").attr("disabled","disabled");
      }
      else {
        //~ $("#edit-field-resume-company-"+k+"-todate-month-wrapper").attr("style","display: visible;");
        $("#edit-field-app-job-history-"+k+"-todate-month").removeAttr('disabled');
        //~ $("#edit-field-resume-company-"+k+"-todate-year").attr("style","display: visible;");
        $("#edit-field-app-job-history-"+k+"-todate-year").removeAttr('disabled');
        //~ $("#edit-field-resume-company-"+k+"-todate-wrapper").attr("style","display: visible;");
        $("#edit-field-app-job-history-"+k+"-todate-wrapper").removeAttr('disabled');
      }
    }
  });
  
  //~ $("input[type=select]").change(function() {
  $(".field-from-date .date-year").change(function() {
    
    this_year = $(".field-from-date .date-year option:last").val();
    //~ this_year = parseInt(this_year)+1;
    
    number = this.id;
    number = number.substr(27);
    pos = number.indexOf('-');
    number = number.substr(0, pos);
    
    var values = "";
    
    /*Create values to populate the to-select with*/
    //~ selected_year = $(".field-from-date .date-year option:selected").val();
    selected_year = $("#edit-field-app-job-history-"+number+"-fromdate-year option:selected").val();
    for(var k = selected_year; k <= this_year; k++) {
      values = values+"<option value='"+k+"'>"+k+"</option>";
    }
    $("#edit-field-app-job-history-"+number+"-todate-year").html(values);
  });
  
});
