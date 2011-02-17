<?php
/**
* Implementation of hook_widget_info().
*/
function jobhistoryfield_widget_info() {
  return array(
    // The machine name of the widget.
    'jobhistoryfield_widget' => array(
      // The human-readable label of the field that will be seen in the Manage fields screen.
      'label' => t('Job history widget'),
      // An array of the field types this widget can be used with.
      'field types' => array('jobhistoryfield'),
      'multiple values' => CONTENT_HANDLE_CORE,
      'callbacks' => array(
        'default value' => CONTENT_CALLBACK_DEFAULT,
      ),
    ),
  );
}

/**
* Implementation of hook_widget().
*/

function jobhistoryfield_widget(&$form, &$form_state, $field, $items, $delta = 0) {
        
    
    
    $vid = 22; //Company vocabulary id
    
    $element['company'] = array(
      '#type'               => 'textfield', 
      '#title'              => t('Company'), 
      '#maxlength'          => 50, 
      '#autocomplete_path'  => 'taxonomy/autocomplete/'.$vid, 
      '#default_value'      => $value = isset($items[$delta]['company']) ? $items[$delta]['company'] : NULL, 
      '#weight'             => -1,
    );
    
    $vid = 10; //Position vocabulary id
    
    $element['position'] = array(
      '#type'               => 'textfield', 
      '#title'              => t('Position held'), 
      '#maxlength'          => 50, 
      '#autocomplete_path'  => 'taxonomy/autocomplete/'.$vid, 
      '#default_value'      => $value = isset($items[$delta]['position']) ? $items[$delta]['position'] : NULL,
      '#weight'             => 0,
    );
    
    $vid = 19; //Industry Vocabulary
    
    //Load the vocabulary to populate the dropdown select
    $vocabulary = taxonomy_get_tree($vid);
    
    //Create the array to hold possible dropdown values
    $industries = array();
    $industries[] = '--Please Select Industry--';
    
    //Populate the industries array_merge
    foreach ($vocabulary as $term) {
      $industries[] = $term->name;
    }
    
    $element['industry'] = array(
      '#type'               => 'select', 
      '#title'              => t('Industry'), 
      '#maxlength'          => 50, 
      '#options'            => $industries,
      '#default_value'      => $value = isset($items[$delta]['industry']) ? $items[$delta]['industry']+1 : NULL, 
      '#weight'             => 1,
      '#prefix'               => '<div class="field-industry">',
      '#suffix'               => '</div>',
    );
    
    $vid = 25; //Job Type
    
    //Load the vocabulary to populate the dropdown select
    $vocabulary = taxonomy_get_tree($vid);
    
    //Create the array to hold possible dropdown values
    $job_types = array();
    
    //Populate the industries array_merge
    foreach ($vocabulary as $term) {
      $job_types[] = $term->name;
    }
    
    $element['job_type'] = array(
      '#type'               => 'select', 
      '#title'              => t('Job Type'), 
      '#maxlength'          => 50, 
      '#options'            => $job_types,
      '#default_value'      => $value = isset($items[$delta]['job_type']) ? $items[$delta]['job_type'] : 1, 
      '#weight'             => 2,
      '#prefix'               => '<div class="field-job-type">',
      '#suffix'               => '</div>',
    );
    
    if ($items[$delta]['todate'] == 'Current')
      $def_val = 1;
    else $def_val = 0;
    
    $element['currentjob'] = array(
      '#type'           => 'checkbox',
      '#title'          => t('I am currently employed here'),
      '#default_value'  => $def_val,
      '#weight'         => 3,
      '#prefix'               => '<div class="field-current-job">',
      '#suffix'               => '</div>',
    );
    
    $element['fromdate'] = array(
      '#type'                 => 'date_select',
      '#title'                => 'From',
      '#date_format'          => 'm-Y',
      '#date_label_position'  => 'within',
      '#date_year_range'      => '-50:0',
      '#default_value'        => isset($items[$delta]['fromdate']) ? $items[$delta]['fromdate'] : date('Y', time()),
      '#prefix'               => '<div class="field-from-date">',
      '#suffix'               => '</div>',
      '#weight'               => 4,
    );
    
    $element['todate'] = array(
      '#type'                 => 'date_select',
      '#title'                => 'To',
      '#date_format'          => 'm-Y',
      '#date_label_position'  => 'within',
      '#date_year_range'      => '-50:0',
      '#default_value'        => isset($items[$delta]['todate']) ? $items[$delta]['todate'] : date('Y', time()),
      '#prefix'               => '<div class="field-to-date">',
      '#suffix'               => '</div>',
      '#weight'               => 5,
    );
    
 
  // Used so that hook_field('validate') knows where to
  // flag an error in deeply nested forms.
  if (empty($form['#parents'])) {
    $form['#parents'] = array();
  }
  $element['_error_element'] = array(
    '#type' => 'company',
    '#value' => implode('][', array_merge($form['#parents'], array('company'))),
  );
 
  return $element;
}
